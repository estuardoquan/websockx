#include <request/protocols/http.h>

#include <stdio.h>

static Dictionary http_request_rules = {
    {"re_request", "^([a-zA-Z0-9*/=_?.,;:()\"' '-]+\n)+)\n\n.+$"},
    {"re_header", "^([a-zA-Z-]+)([:][' '][a-zA-Z0-9*/=_?.,;:()\"' '-]+)?.{1}$"},
    {"re_request_line", "^([A-Z]+)[' ']([/](.?)+)[' '][A-Z]+[/]([0-9]+[.]?)+.{1}$"},
};

enum METHODS
{
    CONNECT,
    DELETE,
    GET,
    HEAD,
    OPTIONS,
    PATCH,
    POST,
    PUT,
    TRACE,
};

static std::unordered_map<std::string_view, int> m_http_methods = {
    {"CONNECT", CONNECT},
    {"DELETE", DELETE},
    {"GET", GET},
    {"HEAD", HEAD},
    {"OPTIONS", OPTIONS},
    {"PATCH", PATCH},
    {"POST", POST},
    {"PUT", PUT},
    {"TRACE", TRACE},
};

Http::Http(const char *buffer) : Request(buffer, http_request_rules)
{
    // for (auto &[k, v] : this->rl)
    //     printf("[%s] = %s\n", k.data(), this->rl[k].data());
    // for (auto &[k, v] : this->rh)
    //     printf("[%s] = %s\n", k.data(), this->rh[k].data());
    return;
}
