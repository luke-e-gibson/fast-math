{
  "targets": [
    {
      # myModule is the name of your native addon
      "target_name": "fastMath",
      "sources": ["src/cpp/main.cpp", "src/cpp/math/basic/basic.cpp", "src/cpp/math/basic/basic.h"],
      'dependencies': [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api",
        ],
    }
  ]
}