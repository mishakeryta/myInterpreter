#ifndef LOGER_HPP
#define LOGER_HPP



#ifdef LOG_ENABLE
#define LOG(val) (std::cout << val)
#else
#define LOG(val)
#endif

#endif // LOGER_HPP
