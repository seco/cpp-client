

#ifndef API_H
#define API_H

#include "connection/connection.h"

#ifdef USE_ONE_API

    #include "api/one/one_api.h"
    typedef ONE_API VersionedAPI;

#elif defined(USE_TWO_API)

    #include "api/two/two_api.h"
    typedef TWO_API VersionedAPI;
    
#endif

#endif
