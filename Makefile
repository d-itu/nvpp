NVIM_VERSION = 0.12.1

HEADERS := $(shell find include -type f -name "*.hh")

.PHONY: all
all: build/lib/libnvpp.so

.PHONY: generate
generate: build/include/nvpp/generated/keysets.hh build/include/nvpp/generated/api.hh

.PHONY: deps
deps: deps/nvim/zig-out/headers

deps/nvim.tar.gz:
	@mkdir -p deps
	curl -L https://github.com/neovim/neovim/archive/refs/tags/v$(NVIM_VERSION).tar.gz -o $@

deps/nvim: deps/nvim.tar.gz
	tar -xzf $< -C deps
	mv deps/neovim-$(NVIM_VERSION) deps/nvim

deps/nvim/zig-out/headers: deps/nvim
	zig build --build-file deps/nvim/build.zig gen_headers

build/include/nvpp/generated/keysets.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/keysets.lua\
	deps/nvim
	@mkdir -p $(dir $@)
	nvim -u NONE -l src/gen/preload.lua gen.keysets > $@

build/include/nvpp/generated/api.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/api.lua\
	deps/nvim
	@mkdir -p $(dir $@)
	nvim -u NONE -l src/gen/preload.lua gen.api > $@

build/lib/libnvpp.so:\
	src/main.cc\
	$(HEADERS)\
	deps\
	generate\
	compile_flags.txt
	clang++ $(shell cat compile_flags.txt) $< -o $@

