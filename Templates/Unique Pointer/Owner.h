#pragma once
#include <memory>
// Our own (decent) take on a unique pointer that we'll call Owner. 
template<typename T>
class Owner {
private:
	// The actual dynamic-storage pointer.
	T* mPtr;

	// Deletes the owned pointer.
	inline void Release() {
		delete mPtr;
	}

	inline void Reset() {
		mPtr = nullptr;
	}








public:
	// Default constructor: sets the pointer to null.
	Owner() : mPtr(nullptr) {}

	// Constructs an Owner over a raw pointer in dynamic storage.
	explicit Owner(T* ptr) : mPtr(ptr) {}
	
	// Move constructor: take ownership of the pointer of another Owner, and reset that Owner.
	Owner(Owner<T> &&moving) : mPtr(std::move(moving.mPtr)) {
		moving.Reset();
	}

	// Move assignment: take ownership of another Owner, but first release your owned data.
	Owner<T>& operator=(Owner<T> &&rhs) {
		if (this == rhs)
			return *this;

		Release();
		mPtr = rhs.mPtr;
		rhs.Reset();
	}
	
	// When an Owner is destroyed, destroy its owned data.
	~Owner() {
		Release();
	}

	// operator->, which returns the raw pointer without claiming ownership, so that a member
	// can be accessed.
	T* operator->() const {
		return mPtr;
	}

	// operator*, which returns the value pointed to without claiming ownership.
	T& operator*() const {
		return *mPtr;
	}

	// Returns the raw pointer without claiming ownership.
	T* get() const {
		return mPtr;
	}







	// Allow an Owner of type T to accept an Owner of type U, if U derives from T.
	template<typename U>
	Owner(Owner<U> &&moving) : mPtr(std::move(moving.mPtr)) {
		moving.Reset();
	}

	template<typename U>
	Owner<T>& operator=(Owner<U> &&moving) {
		Release();
		mPtr = std::move(moving.mPtr);
		moving.Reset();
		return *this;
	}


	// "delete" the copy constructor / copy move operator, which prevents the compiler
	// from creating one for us.
	Owner(const Owner<T> &other) = delete;
	Owner<T>& operator=(const Owner<T> &rhs) = delete;
};


template<typename T, typename... TArgs>
Owner<T> make_owner(TArgs&&... args) {
	return Owner<T>{ new T(args...) };
}