#include <openssl/engine.h>
#include <stdlib.h>
static const char *engine_id = "libng";
static const char *engine_name = "ng example engine by Nathan Grubb";

IMPLEMENT_DYNAMIC_CHECK_FN();

int ng_init(ENGINE *e) {
  fprintf(stderr, "%s called!\n", __func__);
  return 786;
}

extern EC_KEY_METHOD ec_key_method_impl;

int bind_helper(ENGINE * e, const char *id) {
  if (!ENGINE_set_id(e, engine_id) ||
      !ENGINE_set_name(e, engine_name) ||
      !ENGINE_set_init_function(e, ng_init) ||
      !ENGINE_set_EC(e, &ec_key_method_impl)
  ) {
    return 0;
  }

  return 1;
}

IMPLEMENT_DYNAMIC_BIND_FN(bind_helper);
