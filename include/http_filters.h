#ifndef PIGEON_HTTP_FILTERS_H
#define PIGEON_HTTP_FILTERS_H

#include <mutex>
#include <memory>
#include <string>
#include <unordered_map>
#include <http_filter_base.h>

namespace pigeon {

    class http_filters {

    private:

        http_filters();

        static std::mutex _mtx;
        static std::shared_ptr<http_filters> temp;
        std::unordered_map<string, http_filter_base *> filters;

    public:

        ~http_filters();

        http_filters(const http_filters &filters);
        http_filters& operator = (http_filters const &);

        void add(std::string, http_filter_base *);

        http_filter_base *get(std::string &);

        static std::shared_ptr<http_filters> &instance();

    };

}


#endif //PIGEON_HTTP_FILTERS_H