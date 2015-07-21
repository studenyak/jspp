
function main(json_obj) {
    var res_json_obj = {
        "string": "Hello",
        "int": 123,
        "float": 1.23,
        "null": null,
        "Array": [1, 2, 1.23, "string"],
        "json_obj":json_obj
    };
    print(JSON.stringify(res_json_obj));
}