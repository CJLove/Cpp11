//
// std::make_unique() implementation until supported by post-C++11
//

namespace std {
    
    template<typename T, typename ...Args>
    std::unique_ptr<T> make_unique(Args&& ...args)
    {
        return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
    }
    
}
