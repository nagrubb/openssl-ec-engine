#include <stdint.h>
#include <string.h>
#include "internal/ec_key_method_st.h"

const char ec_key_method_impl_name[] = "ng elliptic curve crypto implementation";
static int ec_key_init(EC_KEY* key);
static int ec_key_finish(EC_KEY* key);
static int ec_key_copy(EC_KEY* dest, const EC_KEY* src);
static int ec_key_set_group(EC_KEY* key, const EC_GROUP* grp);
static int ec_key_set_private(EC_KEY* key, const BIGNUM* priv_key);
static int ec_key_set_public(EC_KEY* key, const EC_POINT* pub_key);
static int ec_key_keygen(EC_KEY* key);
static int ec_key_compute_key(uint8_t** pout, size_t* poutlen, const EC_POINT* pub_key, const EC_KEY* ecdh);
static int ec_key_sign(int32_t type, const uint8_t* dgst, int32_t dlen, uint8_t* sig,
  uint32_t* siglen, const BIGNUM* kinv, const BIGNUM* r, EC_KEY* eckey);
static int ec_key_sign_setup(EC_KEY* eckey, BN_CTX* ctx_in, BIGNUM** kinvp, BIGNUM** rp);
static ECDSA_SIG* ec_key_sign_sig(const uint8_t* dgst, int32_t dgst_len, const BIGNUM* in_kinv, const BIGNUM* in_r, EC_KEY* eckey);
static int ec_key_verify(int type, const uint8_t* dgst, int dgst_len, const uint8_t* sigbuf, int32_t sig_len, EC_KEY* eckey);
static int ec_key_verify_sig(const uint8_t* dgst, int dgst_len, const ECDSA_SIG* sig, EC_KEY* eckey);


/* Note if you put NULL for any of the function pointers, OpenSSL will handle gracefully returning
 * that the engine does not implement the specified function.
 */
const EC_KEY_METHOD ec_key_method_impl = {
  ec_key_method_impl_name,    /* name */
  0,                          /* flags */
  ec_key_init,
  ec_key_finish,
  ec_key_copy,
  ec_key_set_group,
  ec_key_set_private,
  ec_key_set_public,
  ec_key_keygen,
  ec_key_compute_key,
  ec_key_sign,
  ec_key_sign_setup,
  ec_key_sign_sig,
  ec_key_verify,
  ec_key_verify_sig
};

int ec_key_init(EC_KEY* key) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_finish(EC_KEY* key) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_copy(EC_KEY* dest, const EC_KEY* src) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_set_group(EC_KEY* key, const EC_GROUP* grp) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_set_private(EC_KEY* key, const BIGNUM* priv_key) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_set_public(EC_KEY* key, const EC_POINT* pub_key) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_keygen(EC_KEY* key) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_compute_key(uint8_t** pout, size_t* poutlen, const EC_POINT* pub_key, const EC_KEY* ecdh) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

int ec_key_sign(int32_t type, const uint8_t* dgst, int32_t dlen, uint8_t* sig, uint32_t* siglen,
                const BIGNUM* kinv, const BIGNUM* r, EC_KEY* eckey) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

static int ec_key_sign_setup(EC_KEY* eckey, BN_CTX* ctx_in, BIGNUM** kinvp, BIGNUM** rp) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}
static ECDSA_SIG* ec_key_sign_sig(const uint8_t* dgst, int32_t dgst_len, const BIGNUM* in_kinv, const BIGNUM* in_r, EC_KEY* eckey) {
  fprintf(stderr, "%s called!\n", __func__);
  return NULL;
}

static int ec_key_verify(int type, const uint8_t* dgst, int dgst_len, const uint8_t* sigbuf, int32_t sig_len, EC_KEY* eckey) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}

static int ec_key_verify_sig(const uint8_t* dgst, int dgst_len, const ECDSA_SIG* sig, EC_KEY* eckey) {
  fprintf(stderr, "%s called!\n", __func__);
  return 1;
}
