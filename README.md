# Open EC Engine Template
This project was just for fun and I'm only publishing it because the OpenSSL documentation is actually out of date.
The goal of this was just to create an OpenSSL Engine to better understand how OpenSSL engine's work. This project
by itself doesn't really do much, but I think it's a good framework for creating other OpenSSL Engines.

# Dependencies
- OpenSSL Libraries
- OpenSSL Executable
- CMake

# Build
This project uses cmake so it's pretty straight forward to build. In case you aren't familiar:
```
git clone
cd
mkdir build
cd build
make
```

# Setup
This is a little bit complicated because it varies from platform to platform. However, the
following instructions are assuming you are using macOS with OpenSSL installed from Brew:
```
# First figure out where OpenSSL's ENGINESDIR is (NOTE: This will only work for Brew's OpenSSL, not macOS's default install)
openssl version -a | grep ENGINESDIR

# Based on the above, lets say our ENGINESDIR was "/usr/local/Cellar/openssl@1.1/1.1.1h/lib/engines-1.1" so lets export that
# to make future instructions easier
export ENGINESDIR=/usr/local/Cellar/openssl@1.1/1.1.1h/lib/engines-1.1

# Now from our build directory, lets symlink our engine into the engines directory (NOTE: We remove the lib because OpenSSL doesn't handle the lib prefix well)
ln -s $(pwd)/libng.dylib ${ENGINESDIR}/ng.dylib

# Double check this symlink worked (this should )
ls -lah ${ENGINESDIR}
#^ The above should output something like
#libng.dylib -> /Users/terminator/openssl-vault/build/ng.dylib


# Double check openssl sees our engine
openssl engine -t ng
#^ The above should output something like
#(ng) ng example engine by Nathan Grubb
#Loaded: (libng) ng example engine by Nathan Grubb
#ng_init called!
#     [ available ]
```

# Test
Since this project doesn't really do anything, it just shows you what functions are called in what order. However,
to trigger that you can use the following ECDSA OpenSSL commands:
```
# Generate a private key
openssl ecparam -name prime256v1 -genkey -noout -out private.pem

# Create an empty file to sign
touch useless_file

# Now lets invoke our engine
openssl dgst -engine ng -sha1 -sign private.pem < useless_file > signature.bin
```

If everything works as intended you should see output like this:
```
ng_init called!
engine "ng" set.
ec_key_init called!
ec_key_sign called!
ec_key_finish called!
```

Note that your signature file will be empty because this code doesn't actually do anything.

# Client Code
To use this engine or any engine in code, you can do something like this before using
the regular OpenSSL functions:
```
OpenSSL_add_all_algorithms();
ERR_load_crypto_strings();

ENGINE_load_dynamic();
ENGINE *engine = ENGINE_by_id("ng");

if( engine == NULL )
{
    printf("Could not Load NG Engine!\n");
    exit(1);
}
printf("NG Engine successfully loaded\n");

int init_res = ENGINE_init(engine);
printf("Engine name: %s init result : %d \n",ENGINE_get_name(engine), init_res);

int er = ENGINE_set_default_EC(engine);
printf("\nENGINE SETTING DEFAULT ECDSA:%d\n",er);
```
