#ifndef LOGER_HPP
#define LOGER_HPP

#define LOG_ENABLED

#ifdef LOG_ENABLED
#define LOG(val) (std::cout << val)
#else
#define LOG(val) ()
#endif

#endif // LOGER_HPP
