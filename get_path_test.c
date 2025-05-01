#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "main.h"

/* Helper function to print test results */
void run_test(const char *description, const char *expected, const char *result) {
    printf("Test: %s\n", description);
    if (result == NULL && expected == NULL) {
        printf("PASSED: Expected and got NULL\n\n");
    } else if (result != NULL && expected != NULL && strcmp(result, expected) == 0) {
        printf("PASSED: Expected '%s' and got '%s'\n\n", expected, result);
    } else {
        printf("FAILED: Expected '%s' but got '%s'\n\n", expected ? expected : "NULL", result ? result : "NULL");
    }
}

/* Main test function */
int main() {
    char *result;

    /* Test 1: Command with absolute path that exists */
    result = get_path("/bin/ls");
    run_test("Absolute path to an existing command", "/bin/ls", result);
    /* Do not free result as it's not dynamically allocated */
    if (result != NULL && strcmp(result, "/bin/ls") != 0){ 
        free(result);
    }

    /* Test 2: Command with absolute path that does not exist */
    result = get_path("/invalid/path");
    run_test("Absolute path to a non-existent command", NULL, result);
    free(result);

    /* Test 3: Command in PATH */
    result = get_path("ls");
    if (result != NULL && strstr(result, "/bin/ls")) {
        run_test("Command found in PATH", result, result);
    } else {
        run_test("Command found in PATH", "/bin/ls", result);
    }
    free(result);

    /* Test 4: Command not in PATH */
    result = get_path("nonexistentcommand");
    run_test("Command not found in PATH", NULL, result);
    free(result);

    /* Test 5: Empty command */
    result = get_path("");
    run_test("Empty command string", NULL, result);
    free(result);

    /* Test 6: PATH environment variable unset */
    unsetenv("PATH");
    result = get_path("ls");
    run_test("PATH environment variable unset", NULL, result);
    setenv("PATH", "/bin:/usr/bin", 1); /* Reset PATH for further tests */

    /* Test 7: Command in a custom PATH directory */
    setenv("PATH", "/usr/local/bin:/bin:/usr/bin", 1);
    result = get_path("ls");
    if (result != NULL && strstr(result, "/bin/ls")) {
        run_test("Command found in custom PATH", result, result);
    } else {
        run_test("Command found in custom PATH", "/bin/ls", result);
    }
    free(result);

    printf("All tests completed.\n");
    return 0;
}

