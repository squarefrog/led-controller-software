# Homebridge TV Lights

Allow control of an LED strip wirelessly, either over web API or [Homebridge](https://github.com/nfarina/homebridge).

## Development Stages

- [ ] Allow setting up WiFi using [WiFiManager](https://github.com/tzapu/WiFiManager)
- [ ] Create a `LightStrip` model
- [ ] Create web server with [Homebridge](https://github.com/nfarina/homebridge) compatible API
- [ ] Connect LED Strip and get basic control working
- [ ] Connect API handler to LED handling code
- [ ] Add in a relay or transistor to switch LED strips on and off
- [ ] Save the current colour as the default boot colour
- [ ] Fabricate a PCB
- [ ] Support OTA updates
- [ ] Create [Homebridge](https://github.com/nfarina/homebridge) plugin
- [ ] Create [Postman](https://www.getpostman.com) API spec

## Hardware

### Bill of Materials (TBC)

- ESP8266 Arduino compatible with built-in WiFi
- WS2812B LED Light Strip - available in different LED densities. I use 30 per meter, which is fine for this purpose
- 300-500 Ohm Resistor - to prevent voltage spikes which could damage the first LED
- 1000 µF 6.3v or higher capacitor - to smooth the current drain from the PSU
- Relay - the LED strip uses 1mA per LED even when the lights are off, so this allows the LED strip to be completely switched off when not in use
- A suitable 5V power supply - see [Power Requirements](#power-requirements).

### Power Requirements

Powering many RGB LEDs requires an appropriate power supply. Each LED draws up to 60mA at maximum brightness white. To estimate the power supply needs multiply the maximum current draw by the number of LEDs. For example, 50 LEDs × 60mA ÷ 1000 = 3A required.

Additionally, the rest of the circuit also needs powering, so ensure your chosen power supply can more than just the LEDs. There is no harm in using a larger power supply, in fact it means the power supply doesn't have to work as hard.

#### Buyer Beware

While it is tempting to get a power supply from eBay, or AliExpress for as little as £4, I'd recommend you spend the extra and get one from a reputable source. For example, I got a 5V 5A Switchable Power Supply from [CPC Farnell](http://cpc.farnell.com/powerpax/ptd-0505pa/ac-adaptor-5v-5a-regulated/dp/PW02604) for just under £20. Yes, thats four times as expensive, but it is safety tested and CE marked. It's worth spending the extra money to reduce the risk of burning your house down.

## Software

### Library Dependencies

- [WiFiManager](https://github.com/tzapu/WiFiManager#install-through-library-manager) - for easily allowing connections to any WiFi access point
- [FastLED](https://github.com/FastLED/FastLED) - for simplified driving of LED strips

### API (WIP)

The API endpoints are listed below. Endpoint value ranges are taken from the [HomeKit Accessory Protocol](https://developer.apple.com/support/homekit-accessory-protocol/), specifically the `Lightbulb` service. Fetching current values returns JSON with a key and value. For example:

    { "key": "hue", "value": 275 }

#### Power

`POST /on?v=true`
Set the current power status, as a `bool` value.

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
