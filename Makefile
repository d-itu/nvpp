NVIM_VERSION := 0.12.1

HEADERS := $(shell find include -type f -name "*.hh")
GENERATED_HEADERS := build/include/nvpp/keysets.hh build/include/nvpp/api.hh

.PHONY: generate
generate: $(GENERATED_HEADERS)

PREFIX ?= /usr/local

.PHONY: install
install: generate
	mkdir -p $(PREFIX)/include/nvpp
	cp -r include/nvpp/* $(PREFIX)/include/nvpp/
	cp -r build/include/nvpp/* $(PREFIX)/include/nvpp/

.PHONY: examples
examples: build/lib/libnvpp.so

.PHONY: deps
deps: deps/nvim/zig-out/headers

deps/nvim.tar.gz:
	@mkdir -p $(@D)
	curl -L https://github.com/neovim/neovim/archive/refs/tags/v$(NVIM_VERSION).tar.gz -o $@

deps/nvim: deps/nvim.tar.gz
	tar -xzf $< -C deps
	mv deps/neovim-$(NVIM_VERSION) deps/nvim

deps/nvim/zig-out/headers: deps/nvim
	zig build --build-file deps/nvim/build.zig gen_headers

build/include/nvpp/keysets.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/keysets.lua\
	deps/nvim
	@mkdir -p $(@D)
	nvim -u NONE -l src/gen/preload.lua gen.keysets > $@

build/include/nvpp/api.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/api.lua\
	deps/nvim
	@mkdir -p $(@D)
	nvim -u NONE -l src/gen/preload.lua gen.api > $@

build/lib/libnvpp.so:\
	examples/nvpp.cc\
	$(HEADERS)\
	$(GENERATED_HEADERS)\
	deps/nvim/zig-out/headers\
	compile_flags.txt
	@mkdir -p $(@D)
	$(CXX) $(shell cat compile_flags.txt) $< -o $@

