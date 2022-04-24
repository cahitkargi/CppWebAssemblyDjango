WAC := em++
WAFLAGS := -sEXPORTED_RUNTIME_METHODS=cwrap -std=c++17
LDFLAGS := -sUSE_SDL=2 -sUSE_SDL_IMAGE=2
BASE_NAME := index
DJANGO_PROJECT := DjangoWebAssembly
DJANGO_APP := cpp
SOURCE := $(BASE_NAME).cc
TARGET := $(BASE_NAME).js

.ONESHELL:
.PHONY: $(BASE_NAME)
$(BASE_NAME): $(SOURCE)
	$(WAC) $(SOURCE) -o $(TARGET) $(WAFLAGS)
	cp $(TARGET) $(DJANGO_PROJECT)/static/$(DJANGO_APP)
	cp $(BASE_NAME).wasm $(DJANGO_PROJECT)/static/$(DJANGO_APP)
