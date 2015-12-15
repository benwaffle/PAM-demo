#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <security/pam_misc.h>

int main() {
    struct pam_conv conv = {
        .conv = &misc_conv,
        .appdata_ptr = NULL
    };

    pam_handle_t *pam = NULL;
    int ret;

    ret = pam_start("pam-demo", NULL, &conv, &pam);
    if (ret != PAM_SUCCESS) {
        fprintf(stderr, "pam_start: %s\n", pam_strerror(pam, ret));
        return 1;
    }

    ret = pam_set_item(pam, PAM_USER_PROMPT, "Username: ");
    if (ret != PAM_SUCCESS) {
        fprintf(stderr, "pam_set_item: %s\n", pam_strerror(pam, ret));
        return 1;
    }

    ret = pam_authenticate(pam, 0);
    printf("%s\n", pam_strerror(pam, ret));

    pam_end(pam, ret);
}

