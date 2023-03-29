#pragma once
#include <memory>

#ifdef _WIN32
	#ifdef _WIN64
		#define HL_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
		#if TARGET_IPHONE_SIMULATOR == 1
			#error "IOS simulator is not supported!"
		#elif TARGET_OS_IPHONE == 1
			#define HL_PLATFORM_IOS
			#error "IOS is not supported!"
		#elif TARGET_OS_MAC == 1
			#define HL_PLATFORM_MACOS
			#error "MacOS is not supported!"
		#else
			#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
	#define HL_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define HL_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	#error "Unknown platform!"
#endif

// DLL support
#ifdef HL_PLATFORM_WINDOWS
	#if HL_DYNAMIC_LINK
		#ifdef HL_BUILD_DLL
			#define HOLOLIB_API __declspec(dllexport)
		#else
			#define HOLOLIB_API __declspec(dllimport)
		#endif
	#else
		#define HOLOLIB_API
	#endif
#else
	#error Hololib only supports Windows!
#endif

//#ifdef HL_DEBUG
	//#define HL_ENABLE_ASSERTS
//#endif

#ifdef HL_ENABLE_ASSERTS
	#define HL_ASSERT(x, ...) { if(!(x)) {HL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define HL_CORE_ASSERT(x, ...) { if(!(x)) { HL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); debugbreak(); }}
#else
	#define HL_ASSERT(x, ...)
	#define HL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace HoloLib {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}