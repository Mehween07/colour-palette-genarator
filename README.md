# 🎨 Colour Palette Generator

A C++ command-line tool that generates complementary, analogous, and triadic colour palettes using HSL colour theory — built as my first C++ project, combining my background in painting with my current journey into programming.

## What it does

Enter any RGB colour, and the program calculates matching colours using the same colour theory principles used in professional design tools:

- **Complementary colours** — the colour directly opposite on the colour wheel
- **Analogous colours** — colours neighbouring yours on the wheel (±30°)
- **Triadic colours** — two colours evenly spaced 120° apart, forming a triangle on the wheel

The program loops, so you can generate as many palettes as you like in one run.

## Why I built this

As someone who paints, I often need quick, reliable colour palette suggestions when planning a piece. Rather than relying on external tools, I decided to build my own — while learning C++ for the first time. This project let me apply real colour theory math (RGB ↔ HSL conversion) alongside core programming concepts like conditionals, loops, and functions.

## How it works

1. Takes RGB input (0–255 for each channel)
2. Converts RGB → HSL (Hue, Saturation, Lightness)
3. Based on the selected menu option, shifts the Hue value (180° for complementary, ±30° for analogous, ±120° for triadic)
4. Converts the new HSL values back to RGB
5. Displays the result(s)

## Tech used

- **Language:** C++
- **Concepts:** conditionals, loops, functions, HSL/RGB colour space conversion

## Running it locally

```bash
g++ palette.cpp -o palette
./palette
