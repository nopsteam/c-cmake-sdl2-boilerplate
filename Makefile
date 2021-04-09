setup:
	cmake -DCMAKE_BUILD_TYPE=Debug -B build/debug
	cmake -DCMAKE_BUILD_TYPE=Release -B build/release
.PHONY: setup

debug:
	make --no-print-directory -C build/debug
.PHONY: debug

release:
	make --no-print-directory -C build/release
.PHONY: release

test:
	make --no-print-directory -C build/debug
	make --no-print-directory -C build/debug test ARGS='--output-on-failure'
.PHONY: test

clean:
	make --no-print-directory -C build/debug clean
	make --no-print-directory -C build/release clean
.PHONY: clean

coverage:
	cmake -DCMAKE_BUILD_TYPE=Coverage -B build/coverage
	make --no-print-directory -C build/coverage -j
	make --no-print-directory -C build/coverage coverage
.PHONY: coverage

TITLE=example_app

linux:
	cmake -DCMAKE_BUILD_TYPE=Release -B build/release
	make --no-print-directory -C build/release
	mkdir -p build/release/linux
	cp build/release/bin/$(TITLE) build/release/linux/
	find build/release/bin/ -type f -iname "*.so" -exec cp {} build/release/linux/ \;
	cp -r build/release/resources build/release/linux/
	find /usr/lib -type f -iname "*sdl2*.so.*" -exec cp {} build/release/linux/ \;
	for FILE in $$(find build/release/linux/ -type f -iname "*.so.0.*"); do ln -sfv $$(basename $${FILE}) $$(echo $${FILE} | sed 's/.so.0.*/.so.0/'); done
.PHONY: linux

mac:
	cmake -DCMAKE_BUILD_TYPE=Release -B build/release
	make --no-print-directory -C build/release
	mkdir -p build/release/mac/$(TITLE).app/Contents/Resources/
	cp build/release/bin/$(TITLE) build/release/mac/$(TITLE).app/Contents/Resources/
	cp -r build/release/resources build/release/mac/$(TITLE).app/Contents/Resources/
	find /usr/local/Cellar -type f -iname "*sdl2*.dylib" -exec cp {} build/release/mac/$(TITLE).app/Contents/Resources/ \;
.PHONY: mac

windows:
	cmake -DCMAKE_BUILD_TYPE=Release -B build/release
	nmake --no-print-directory -C build/release
	mkdir build\release\windows
	copy build\release\bin\$(TITLE).exe build\release\windows\ &
	robocopy resources\ build\release\windows\resources\ /e &
	robocopy build\release\bin\ build\release\windows\ *.dll &
	robocopy C:\INCLUDE\SDL2\ build\release\windows\ *.dll &
.PHONY: windows
