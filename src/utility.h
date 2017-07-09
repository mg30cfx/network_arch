#ifndef UTILITY_H_
#define UTILITY_H_

/*
 * Macro to define os version
 */

#if defined(_WIN32)	// Windows
	#if WINVER==0x0501 // XP
		#define PLATFORM_NAME "windowsXP"
	#elif WINVER==0x0701 // 7
    	#define PLATFORM_NAME "windows7"
	#endif

#elif defined(_WIN64)
	#if WINVER==0x0501 // XP
		#define PLATFORM_NAME "windowsXP"
	#elif WINVER==0x0701 // 7
    	#define PLATFORM_NAME "windows7"
	#endif

#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)

#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other

#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif

#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX

#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX

#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif

#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana

#else
    #define PLATFORM_NAME NULL

#endif

/*
 * General define
 */

/*
 * Function prototype
 */

char *get_platform_name(void);
int check_file_exist(char *path);
void get_sys_info(void);

#endif /* UTILITY_H_ */
