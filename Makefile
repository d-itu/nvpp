NVIM_VERSION := 0.12.1

NVIM ?= nvim

HEADERS := $(shell find include -type f -name "*.hh")
GENERATED_HEADERS := build/include/nvpp/keysets.hh build/include/nvpp/api.hh

.PHONY: generate
generate: $(GENERATED_HEADERS)

PREFIX ?= /usr/local

.PHONY: nvim-bin
nvim-bin: nvim-linux-x86_64/bin/nvim

nvim-linux-x86_64.tar.gz:
	curl -L https://github.com/neovim/neovim/releases/download/v$(NVIM_VERSION)/nvim-linux-x86_64.tar.gz -o $@

nvim-linux-x86_64/bin/nvim: nvim-linux-x86_64.tar.gz
	tar xzvf $<

.PHONY: install_headers
install_headers: generate
	mkdir -p $(PREFIX)/include/nvpp
	cp -r include/nvpp/* $(PREFIX)/include/nvpp/
	cp -r build/include/nvpp/* $(PREFIX)/include/nvpp/

.PHONY: distribute
distribute: install_headers
	cp -r templates/* $(PREFIX)

.PHONY: examples
examples: build/lib/libnvpp.so

.PHONY: deps
deps: deps/nvim

deps/nvim.tar.gz:
	@mkdir -p $(@D)
	curl -L https://github.com/neovim/neovim/archive/refs/tags/v$(NVIM_VERSION).tar.gz -o $@

deps/nvim: deps/nvim.tar.gz
	tar -xzf $< -C deps
	mv deps/neovim-$(NVIM_VERSION) deps/nvim

build/include/nvpp/keysets.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/keysets.lua\
	deps/nvim
	@mkdir -p $(@D)
	$(NVIM) -u NONE -l src/gen/preload.lua gen.keysets > $@

build/include/nvpp/api.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/api.lua\
	deps/nvim
	@mkdir -p $(@D)
	$(NVIM) -u NONE -l src/gen/preload.lua gen.api > $@

build/lib/libnvpp.so:\
	examples/nvpp.cc\
	$(HEADERS)\
	$(GENERATED_HEADERS)\
	compile_flags.txt
	@mkdir -p $(@D)
	$(CXX) $(shell cat compile_flags.txt) $< -o $@

