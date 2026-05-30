#include <check.h>
#include <stdlib.h>
#include <locale.h>
#include "8.h"

START_TEST(test_pal_pr) {
    ck_assert_msg(pal(L"аш") == true, "Ошибка: шалаш должен быть палиндромом");
} END_TEST

START_TEST(test_ne_pal) {
    ck_assert_msg(pal(L"привет") == false, "Ошибка: привет не палиндром");
} END_TEST

START_TEST(test_glas_ob) {
    ck_assert_int_eq(glas(L"программирование"), 7);
} END_TEST

START_TEST(test_bez_glas) {
    ck_assert_int_eq(glas(L"всплеск"), 1);
    ck_assert_int_eq(glas(L"хм"), 0);
} END_TEST

START_TEST(test_shortw) {
    ck_assert_msg(pal(L"я") == true, "Ошибка: одна буква всегда палиндром");
    ck_assert_int_eq(glas(L"и"), 1);
} END_TEST


Suite* str_suite(void) {
    Suite *s = suite_create("StringTests");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_pal_pr);
    tcase_add_test(tc_core, test_ne_pal);
    tcase_add_test(tc_core, test_glas_ob);
    tcase_add_test(tc_core, test_bez_glas);
    tcase_add_test(tc_core, test_shortw);
    
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    setlocale(LC_ALL, "");
    int k_oshibok;
    Suite *s = str_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    k_oshibok = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (k_oshibok == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
