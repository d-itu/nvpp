NVIM_VERSION = 0.12.1
NVIM_SRC = deps/neovim-$(NVIM_VERSION)
ZIG_BUILD = $(NVIM_SRC)/build.zig

HEADERS := $(shell find include -type f -name "*.hh")

.PHONY: all
all: build/lib/libnvpp.so

%/:
	mkdir -p $@

deps/nvim.tar.gz: deps/
	curl -L https://github.com/neovim/neovim/archive/refs/tags/v$(NVIM_VERSION).tar.gz -o $@

$(ZIG_BUILD): deps/nvim.tar.gz
	tar -xzf $< -C deps

$(NVIM_SRC)/zig-out/headers: $(ZIG_BUILD)
	zig build --build-file $(NVIM_SRC)/build.zig gen_headers

build/include/nvpp/generated/keysets.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/keysets.lua\
	$(NVIM_SRC)
	@mkdir -p $(dir $@)
	nvim -u NONE -l src/gen/preload.lua gen.keysets > $@

build/include/nvpp/generated/api.hh:\
	src/gen/preload.lua\
	src/gen/map_type.lua\
	src/gen/api.lua\
	$(NVIM_SRC)
	@mkdir -p $(dir $@)
	nvim -u NONE -l src/gen/preload.lua gen.api > $@

build/lib/libnvpp.so:\
	src/main.cc\
	src/nvpp.hh\
	$(HEADERS)\
	build/include/nvpp/generated/keysets.hh\
	build/include/nvpp/generated/api.hh\
	compile_flags.txt build/lib/ $(NVIM_SRC)/zig-out/headers
	clang++ $(shell cat compile_flags.txt) $< -o $@

