# Arduino TX3

*Protocol of the Lacrosse TX3-TH thermo/hygro sensor implemented for Arduino*

You can find the documentation of the protocol [here](http://www.f6fbb.org/domo/sensors/tx3_th.php). You can transmit

- temperature
- humidity

Special thanks to [Oskar Neumann](https://github.com/oskarn97) for the code hints :)

## Usage

You can use a 433MHz transmitter for Arduino (like the FS1000A) to send your temperature and humidity wireless. If you are using a home automation system like fhem, just attach a nanoCUL (CC1101) with flashed [a-culfw](https://github.com/heliflieger/a-culfw) and everything will be created automatically.

## Contributors

- Oskar Neumann
- Matthias Kleine

## LICENSE

MIT License

Copyright (c) 2018 Matthias Kleine

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
