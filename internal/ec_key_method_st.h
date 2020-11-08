#ifndef __EC_KEY_METHOD_ST_H__
#define __EC_KEY_METHOD_ST_H__

#include <openssl/ec.h>

typedef int (*fn_init_t)(EC_KEY* key);
typedef int (*fn_finish_t)(EC_KEY* key);
typedef int (*fn_copy_t)(EC_KEY* dest, const EC_KEY* src);
typedef int (*fn_set_group_t)(EC_KEY* key, const EC_GROUP* grp);
typedef int (*fn_set_private_t)(EC_KEY* key, const BIGNUM* priv_key);
typedef int (*fn_set_public_t)(EC_KEY* key, const EC_POINT* pub_key);
typedef int (*fn_keygen_t)(EC_KEY* key);
typedef int (*fn_compute_key_t)(uint8_t** pout, size_t* poutlen, const EC_POINT* pub_key, const EC_KEY* ecdh);
typedef int (*fn_sign_t)(int32_t type, const uint8_t* dgst, int dlen, uint8_t* sig, uint32_t* siglen, const BIGNUM* kinv, const BIGNUM* r, EC_KEY* eckey);
typedef int (*fn_sign_setup_t)(EC_KEY* eckey, BN_CTX* ctx_in, BIGNUM** kinvp, BIGNUM** rp);
typedef ECDSA_SIG* (*fn_sign_sig_t)(const uint8_t* dgst, int32_t dgst_len, const BIGNUM* in_kinv, const BIGNUM* in_r, EC_KEY* eckey);
typedef int (*fn_verify_t)(int type, const uint8_t* dgst, int dgst_len, const uint8_t* sigbuf, int32_t sig_len, EC_KEY* eckey);
typedef int (*fn_verify_sig_t)(const uint8_t* dgst, int dgst_len, const ECDSA_SIG* sig, EC_KEY* eckey);

struct ec_key_method_st {
    const char *name;
    int32_t flags;
    fn_init_t init;
    fn_finish_t finish;
    fn_copy_t copy;
    fn_set_group_t set_group;
    fn_set_private_t set_private;
    fn_set_public_t set_public;
    fn_keygen_t fn_keygen_t;
    fn_compute_key_t compute_key;
    fn_sign_t sign;
    fn_sign_setup_t sign_setup;
    fn_sign_sig_t sign_sig;
    fn_verify_t verify;
    fn_verify_sig_t verify_sig;
};

#endif //__EC_KEY_METHOD_ST_H__
