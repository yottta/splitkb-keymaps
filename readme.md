## Prerequisites
1. [QMK](https://docs.qmk.fm/#/newbs_getting_started)

# Using qmk-userspace

* Just clone the qmk_firmware:
  ```bash
  git clone https://github.com/qmk/qmk_firmware
  ```
* Configure your userspace:
  ```bash
  qmk config user.overlay_dir=`realpath ../splitkb-keymaps`
  ```
* (Optional): Ensure that the userspace is configured correctly: 
  ```bash
  qmk userspace-list
  ```
* Build all of the keyboards registered: 
  ```bash
  qmk userspace-compile -e CONVERT_TO=liatris
  ```


# Alternative usage
In case userspace is not working as expected, you need to copy (link) your keymap(s) into the firmware dir and compile manually:
```bash
mkdir -p keyboards/splitkb/aurora/sofle_v2/keymaps/personal
cp * <qmk_firware_dir>/keyboards/splitkb/aurora/sofle_v2/keymaps/personal/
qmk compile -kb splitkb/aurora/sofle_v2/rev1 -km personal -e CONVERT_TO=liatris
```
