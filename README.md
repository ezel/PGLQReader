# PGLQRead
A C program to view Pokemon Rental Teams from the QR raw data. This tool is more like a C port of [PKRentalViewer](https://github.com/Phil-DS/PKRentalViewer) so I can run on Mac/Linux.

# How to use
1. Download some .png of QR Rental Team from the [PGL](https://3ds.pokemon-gl.com/) by you favourite browser.
2. Open Command Prompt or Terminal.
3. Navigate to the folder that contains pglqread executable.
4. (Optionally) Type `make` to compile the source.
5. Type `pglqread qr.png` (`qr.png` is the name of your .png file)

# More Usage
* Comming soon

# Known Issues
 * Some QR codes cause decrypt errors.

# Dependencies
* Type `brew install openssl libjpeg libpng` to install the libraries.
* [OpenSSL](https://openssl.org) 
* [libpng](http://www.libpng.org/pub/png/libpng.html) 
* [libjpeg](http://libjpeg.sourceforge.net/)

# Other Libraries Used
* The QR decoder is from [quirc](https://github.com/dlbeer/quirc).
* The MemeCrypto library and most of the data files came from [PKHeX](https://github.com/kwsch/PKHeX).

# Credits:
* The main idea comes from [PKRentalViewer](https://github.com/Phil-DS/PKRentalViewer).
* [@SciresM](https://twitter.com/sciresm?lang=en) for laying out the process for [Rental QR decoding.](https://gist.github.com/SciresM/f3d20f8c77f5514f2d142c9760939266)
* Memecrypto code are taken and modified from SciresM's [memecrypto_test](https://github.com/SciresM/memecrypto_test) and RainThunder's [MassClone](https://github.com/RainThunder/MassClone).
