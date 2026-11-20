#!/usr/bin/env python3
"""Generate release icons from the tracked Josette artwork.

Requires Pillow. Generated files are checked in, so Pillow is only needed when
regenerating them.
"""

from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "resources/icons/wpj2-source.png"
ICON_SIZES = (16, 32, 48, 64, 128, 256)


def main() -> None:
    image = Image.open(SOURCE).convert("RGBA")
    if image.width != image.height:
        raise ValueError("source icon must be square")

    for size in ICON_SIZES:
        target = ROOT / f"resources/icons/hicolor/{size}x{size}/apps/wpj2.png"
        target.parent.mkdir(parents=True, exist_ok=True)
        image.resize((size, size), Image.Resampling.LANCZOS).save(target)

    ico = ROOT / "resources/wpj2.ico"
    image.save(ico, sizes=[(size, size) for size in ICON_SIZES])
    print(f"Wrote {len(ICON_SIZES)} PNG icons and {ico}")


if __name__ == "__main__":
    main()
