var g_arg1 = 1;
var g_arg2 = 2;

var g_obj = {
    "name": "Alex",
    "position": "Astronavt",
    "age": 123
};

function hi(arg1, arg2, json_obj) {
    print("Global object", JSON.stringify(g_obj));
    print("Global variables", g_arg1, g_arg2);
    print("Hello from javascript function(", arg1, arg2, ")");
    print("Input object:", JSON.stringify(json_obj));
}

function main() {
    var json_obj = {
        "string": "Hello",
        "int": 123,
        "float": 1.23,
        "null": null,
        "Array": [1, 2, 1.23, "string"]
    };
    hi("sdfas", "asdfasd", json_obj);
}

function hello_world() {
    print("Hello");
}

function main_p(json_obj) {
    print(JSON.stringify(json_obj));
    return "It works";
}