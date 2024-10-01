#!/bin/bash

DEFCONFIG="lineage-ivan_defconfig"

make -j"$(nproc --all)" O=out ARCH=arm64 SUBARCH=arm64 "$DEFCONFIG"
cp -af out/.config arch/arm64/configs/"$DEFCONFIG"
git add arch/arm64/configs/"${DEFCONFIG}"
git commit -m "ivan-defconfig: Successfully regenerated defconfig" --author "Notganesh<chimeports@gmail.com>"
echo -e "\nSuccessfully regenerated defconfig at $DEFCONFIG"
