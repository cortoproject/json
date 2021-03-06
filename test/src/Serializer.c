/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


static corto_string json_fromCorto(corto_object object) {
    corto_value v = corto_value_object(object, NULL);
    return json_fromValue(NULL, &v);
}

void test_Serializer_tc_serAnyCollection(
    test_Serializer this)
{

    corto_any *o = corto_create(NULL, NULL, corto_any_o);
    o->type = corto_type(corto_int32List_o);
    o->value = test_list_o;
    o->owner = FALSE;

    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"type\":\"list[int32,0]\",\"value\":[10,20,30]}");

}

void test_Serializer_tc_serAnyComposite(
    test_Serializer this)
{

    corto_any *o = corto_create(NULL, NULL, corto_any_o);
    o->type = corto_type(test_Point_o);
    o->value = test_p_o;
    o->owner = FALSE;

    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"type\":\"/test/Point\",\"value\":{\"x\":10,\"y\":20}}");

}

void test_Serializer_tc_serAnyPrimitive(
    test_Serializer this)
{

    corto_any *o = corto_create(NULL, NULL, corto_any_o);
    o->type = corto_type(corto_int8_o);
    o->value = test_int8_o;
    o->owner = FALSE;

    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"type\":\"int8\",\"value\":10}");

}

void test_Serializer_tc_serArray(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_array_o);
    test_assertstr(s, "[10,20,30]");
    corto_dealloc(s);

}

void test_Serializer_tc_serArrayComplex(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_arrayComplex_o);
    test_assertstr(s, "[{\"x\":10,\"y\":20},{\"x\":30,\"y\":40},{\"x\":50,\"y\":60}]");
    corto_dealloc(s);

}

void test_Serializer_tc_serBinary(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_binary_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serBitmask(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_bitmask_o);
    test_assertstr(s, "\"Beef|Cheese|Lettuce|Tomato\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serBoolFalse(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_boolFalse_o);
    test_assertstr(s, "false");
    corto_dealloc(s);

}

void test_Serializer_tc_serBoolTrue(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_boolTrue_o);
    test_assertstr(s, "true");
    corto_dealloc(s);

}

void test_Serializer_tc_serChar(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_char_o);
    test_assertstr(s, "\"a\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serCharEscape(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_charEscape_o);
    test_assertstr(s, "\"\\\\\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serCharNull(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_charNull_o);
    test_assertstr(s, "\"\"");
    corto_dealloc(s);


}

void test_Serializer_tc_serComposite(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_p_o);
    test_assertstr(s, "{\"x\":10,\"y\":20}");
    corto_dealloc(s);

}

void test_Serializer_tc_serCompositeNested(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_l_o);
    test_assertstr(s, "{\"start\":{\"x\":10,\"y\":20},\"stop\":{\"x\":30,\"y\":40}}");
    corto_dealloc(s);

}

void test_Serializer_tc_serCompositeNestedRef(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_l_ref_o);
    test_assertstr(
      s,
      "{\"start\":{\"type\":\"/test/PointRef\",\"value\":{\"x\":10,\"y\":20}},\"stop\":{\"type\":\"/test/PointRef\",\"value\":{\"x\":30,\"y\":40}}}"
    );
    corto_dealloc(s);

}

void test_Serializer_tc_serCompositeObservable(
    test_Serializer this)
{
    test_ObservableType__create_auto(NULL, o, 10, 20, 30);
    test_assert(o != NULL);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"x\":10,\"y\":20,\"z\":30}");
    corto_dealloc(s);
    corto_delete(o);

}

void test_Serializer_tc_serCompositeOptionalNotSet(
    test_Serializer this)
{
    test_OptionalType__create_auto(NULL, o, 10, 20, not_set);
    test_assert(o != NULL);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"x\":10,\"y\":20}");
    corto_dealloc(s);
    corto_delete(o);

}

void test_Serializer_tc_serCompositeOptionalSet(
    test_Serializer this)
{
    test_OptionalType__create_auto(NULL, o, 10, 20, set(30));
    test_assert(o != NULL);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"x\":10,\"y\":20,\"z\":30}");
    corto_dealloc(s);
    corto_delete(o);

}

void test_Serializer_tc_serCompositeRef(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_p_ref_o);
    test_assertstr(s, "{\"x\":10,\"y\":20}");
    corto_dealloc(s);

}

void test_Serializer_tc_serCompositeTarget(
    test_Serializer this)
{
    test_TargetType__create_auto(NULL, o, 10, 20, 30);
    test_assert(o != NULL);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"x\":10,\"y\":20,\"z\":{\"actual\":30,\"target\":0,\"objective\":0}}");
    corto_dealloc(s);
    corto_delete(o);

}

void test_Serializer_tc_serCompositeUnion(
    test_Serializer this)
{
    test_UnionType__create_flt_auto(NULL, o, 1, 10.5);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"_d\":1,\"flt\":10.500000}");
    corto_dealloc(s);

}

void test_Serializer_tc_serCompositeUnionComplex(
    test_Serializer this)
{
    test_Point p = {10, 20};
    test_UnionType__create_pt_auto(NULL, o, 4, &p);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"_d\":4,\"pt\":{\"x\":10,\"y\":20}}");
    corto_dealloc(s);

}

void test_Serializer_tc_serCompositeUnionDefault(
    test_Serializer this)
{
    test_UnionType__create_other_auto(NULL, o, 5, 10);
    corto_string s = json_fromCorto(o);
    test_assertstr(s, "{\"_d\":5,\"other\":10}");
    corto_dealloc(s);

}

void test_Serializer_tc_serEnum(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_enum_o);
    test_assertstr(s, "\"Yellow\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serInheritance(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_p3d_o);
    test_assertstr(s, "{\"super\":{\"x\":10,\"y\":20},\"z\":30}");
    corto_dealloc(s);

}

void test_Serializer_tc_serInheritanceRef(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_p3d_ref_o);
    test_assertstr(s, "{\"super\":{\"x\":10,\"y\":20},\"z\":30}");
    corto_dealloc(s);

}

void test_Serializer_tc_serInt16(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int16_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serInt16Minus(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int16Minus_o);
    test_assertstr(s, "-10");
    corto_dealloc(s);
}

void test_Serializer_tc_serInt32(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int32_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serInt32Minus(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int32Minus_o);
    test_assertstr(s, "-10");
    corto_dealloc(s);
}

void test_Serializer_tc_serInt64(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int64_o);
    test_assertstr(s, "10");
    corto_dealloc(s);
}

void test_Serializer_tc_serInt64Minus(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int64Minus_o);
    test_assertstr(s, "-10");
    corto_dealloc(s);

}

void test_Serializer_tc_serInt8(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int8_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serInt8Minus(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_int8Minus_o);
    test_assertstr(s, "-10");
    corto_dealloc(s);

}

void test_Serializer_tc_serList(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_list_o);
    test_assertstr(s, "[10,20,30]");
    corto_dealloc(s);

}

void test_Serializer_tc_serListComplex(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_listComplex_o);
    test_assertstr(s, "[{\"x\":10,\"y\":20},{\"x\":30,\"y\":40},{\"x\":50,\"y\":60}]");
    corto_dealloc(s);

}

void test_Serializer_tc_serNaN(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_fltNan_o);
    test_assertstr(s, "null"); /* JSON doesn't support nan */
    corto_dealloc(s);

}

void test_Serializer_tc_serReference(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_reference_o);
    test_assertstr(s, "{\"r\":\"package\"}");
    corto_dealloc(s);

}

void test_Serializer_tc_serReferenceAnonymous(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceAnonymous_o);
    test_assertstr(s, "{\"r\":{\"type\":\"int32\",\"value\":10}}");
    corto_dealloc(s);
}

void test_Serializer_tc_serReferenceAnonymousCollection(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceAnonymousCollection_o);
    test_assertstr(s, "{\"r\":{\"type\":\"/test/myList\",\"value\":[10,20]}}");
    corto_dealloc(s);
}

void test_Serializer_tc_serReferenceAnonymousCollectionAnonymousType(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceAnonymousCollectionAnonymousType_o);
    test_assertstr(s, "{\"r\":{\"type\":\"array[int32,2]\",\"value\":[10,20]}}");
    corto_dealloc(s);
}

void test_Serializer_tc_serReferenceAnonymousComplex(
    test_Serializer this)
{
    corto_string s = json_fromCorto(test_referenceAnonymousComplex_o);
    test_assertstr(s, "{\"r\":{\"type\":\"/test/Point\",\"value\":{\"x\":10,\"y\":20}}}");
    corto_dealloc(s);
}

void test_Serializer_tc_serReferenceAnonymousComplexWithString(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceAnonymousComplexString_o);
    test_assertstr(s, "{\"r\":{\"type\":\"/test/StringType\",\"value\":{\"s1\":\"Hello\",\"s2\":\"World\"}}}");
    corto_dealloc(s);
}

void test_Serializer_tc_serReferenceAnonymousComplexWithStringEsc(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceAnonymousComplexStringEsc_o);
    test_assertstr(s, "{\"r\":{\"type\":\"/test/StringType\",\"value\":{\"s1\":\"\\\"Hello\\\"\",\"s2\":\"\\\"World\\\"\"}}}");
    corto_dealloc(s);

}

void test_Serializer_tc_serReferenceFromLang(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceFromLang_o);
    test_assertstr(s, "{\"r\":\"type\"}");
    corto_dealloc(s);

}

void test_Serializer_tc_serReferenceNull(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_referenceNull_o);
    test_assertstr(s, "{\"r\":null}");
    corto_dealloc(s);

}

void test_Serializer_tc_serSequence(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_sequence_o);
    test_assertstr(s, "[10,20,30]");
    corto_dealloc(s);

}

void test_Serializer_tc_serSequenceComplex(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_sequenceComplex_o);
    test_assertstr(s, "[{\"x\":10,\"y\":20},{\"x\":30,\"y\":40},{\"x\":50,\"y\":60}]");
    corto_dealloc(s);

}

void test_Serializer_tc_serString(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_string_o);
    test_assertstr(s, "\"Hello World\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serStringEmpty(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_stringEmpty_o);
    test_assertstr(s, "\"\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serStringEscape(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_stringEscape_o);
    test_assertstr(s, "\"\\\\\"");
    corto_dealloc(s);

}

void test_Serializer_tc_serStringNull(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_stringNull_o);
    test_assertstr(s, "null");
    corto_dealloc(s);

}

void test_Serializer_tc_serStringWhitespace(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_stringWhitespace_o);
    test_assertstr(s, "\" \"");
    corto_dealloc(s);

}

void test_Serializer_tc_serUint16(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_uint16_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serUint32(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_uint32_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serUint64(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_uint64_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serUint8(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_uint8_o);
    test_assertstr(s, "10");
    corto_dealloc(s);

}

void test_Serializer_tc_serVoid(
    test_Serializer this)
{

    corto_string s = json_fromCorto(test_void_o);
    test_assertstr(s, "{}");
    corto_dealloc(s);

}
