# ESP LED Controller

Allow control of an LED strip wirelessly, either over web API or [Homebridge](https://github.com/nfarina/homebridge), using an ESP8266 module.

## Features

- [x] Allow setting up WiFi using [WiFiManager](https://github.com/tzapu/WiFiManager)
- [x] Simple API
- [x] Support OTA updates
- [x] [Homebridge](https://github.com/nfarina/homebridge) plugin - [available here](https://github.com/squarefrog/homebridge-led-controller)

## Hardware

### Bill of Materials

- [Adafruit Huzzah Breakout](https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/overview) - ESP8266 breakout board, any ESP8266 will probably work, but this one is nice and small
- WS2812B LED Light Strip - available in different LED densities. I use 30 per meter, which is fine for my purpose
- 150-200 Ohm Resistor - to prevent voltage spikes which could damage the first LED
- 1000 µF or higher capacitor - to smooth the current drain from the PSU when animating
- A suitable 5V power supply - see [Power Requirements](#power-requirements)

#### Optional

If using the [PCB layout](https://github.com/squarefrog/led-controller), you will also need:

- DC Jack - Cliff DC10A, or DC10L
- 3-way Terminal Block - 3.5mm pitch, or you can just solder the wires direct to the PCB
- 0.1" pitch female pin headers - this allows you to remove the Huzzah without desoldering
- M2.5 screws - for mounting to your project case
- 3D printed enclosure, or any suitable project case

### Power Requirements

Powering many RGB LEDs requires an appropriate power supply. Each LED draws up to 60mA at maximum brightness white. To estimate the power supply needs multiply the maximum current draw by the number of LEDs. For example, 50 LEDs × 60mA ÷ 1000 = 3A required.

Additionally, the rest of the circuit also needs powering, so ensure your chosen power supply can more than just the LEDs. There is no harm in using a larger power supply, in fact it means the power supply doesn't have to work as hard.

#### Buyer Beware

While it is tempting to get a power supply from eBay, or AliExpress for as little as £4, I'd recommend you spend the extra and get one from a reputable source. For example, I got a 5V 5A Switchable Power Supply from [CPC Farnell](http://cpc.farnell.com/powerpax/ptd-0505pa/ac-adaptor-5v-5a-regulated/dp/PW02604) for just under £20. Yes, thats four times as expensive, but it is safety tested and CE marked. It's worth spending the extra money to reduce the risk of burning your house down.

## Software

### Library Dependencies

- [WiFiManager](https://github.com/tzapu/WiFiManager#install-through-library-manager) - for easily allowing connections to any WiFi access point
- [FastLED](https://github.com/FastLED/FastLED) - for simplified driving of LED strips

### API

The API endpoints are listed below. Endpoint value ranges are taken from the [HomeKit Accessory Protocol](https://developer.apple.com/support/homekit-accessory-protocol/), specifically the `Lightbulb` service. Fetching current values returns JSON with the current value. For example:

    { "status": "ok", value": 42 }

#### Power

`POST /on?v={val}`
Set the current power status, as a `bool` value. Either `true` or `false`.

`GET /on`
Returns the current power status as a `bool`.

#### Hue

`POST /hue?v={val}`
Set Hue value. Range `0-360`.

`GET /hue`
Get the current Hue value.

#### Saturation

`POST /saturation?v={val}`
Set Saturation value. Range `0-100`.

`GET /saturation`
Get the current Saturation value.

#### Brightness

`POST /brightness?v={val}`
Set Brightness value. Range `0-100`.

`GET /brightness`
Get the current Brightness value.

#### Name

`POST /name?v={val}`
Update the LED strip name. Name should be a `String` with a maximum length of 64.

`GET /name`
Get the current Name value.

#### Save Default Colour

`POST /save-default`
Store the current colour as the default colour. This will be used when the unit power is switched on.

## References

- [Powering NeoPixels](https://learn.adafruit.com/adafruit-neopixel-uberguide/powering-neopixels)
