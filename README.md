# A minimal example of using WebAssembly (compiled from C++) with Django

To run the example as it is:

1. First, you need to create a `.env` file in the same folder as `manage.py` and add a secret key `SECRET_KEY = 'secret string key goes here'`
1. Then, run Django development server (`python manage.py runserver`)

If you make changes to C++ code (ie `index.cc`):

1. You need to re-build the `index.js` and `index.wasm` , and you may use the provided `makefile` for this and simply run `make index` which will re-build and also copy the output files into `DjangoWebAssembly/static/cpp`. If you build it with an alternative way, make sure that the `index.js` and `index.wasm` files under `DjangoWebAssembly/static/cpp` are the latest.
1. The rest is the same as above (ie, you need to create a `.env` with `SECRET_KEY` and run the development server)
