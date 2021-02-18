#include <stdio.h>
#include <string.h>
#include <iostream>
#include <nlohmann/json.hpp>

extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}

#include <httplib.h>

using json = nlohmann::json;

int main (void) {
  json j;
  j["Hello"] = "world";

  // HTTP
  httplib::Server svr;

  svr.Get("/hi", [j](const httplib::Request &, httplib::Response &res) {
    res.set_content(j.dump().c_str(), "text/plain");
  });

  svr.listen("0.0.0.0", 8080);

  char buff[256];
  int error;
  lua_State *L = luaL_newstate();
  luaL_openlibs(L); 

  while (fgets(buff, sizeof(buff), stdin) != NULL) {
    error = luaL_loadbuffer(L, buff, strlen(buff), "line") || lua_pcall(L, 0, 0, 0);
    if (error) {
      fprintf(stderr, "%s", lua_tostring(L, -1));
      lua_pop(L, 1); // Pop error 
    }
  }

  lua_close(L);
  return 0;
}