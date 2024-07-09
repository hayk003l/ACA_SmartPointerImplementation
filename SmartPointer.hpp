#ifndef __SMARTPOINTER__
#define __SMARTPOINTER__

template <typename T>
class smart_ptr {
public:
    smart_ptr(T* ptr) : m_ptr(ptr) {}
    ~smart_ptr() {
        delete m_ptr;
        m_ptr = nullptr;
    }

    smart_ptr(smart_ptr<T>&& ptr) noexcept {
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }

    smart_ptr& operator=(smart_ptr<T>&& ptr) noexcept {
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }

    T& operator*() {
        return *m_ptr;
    }

    T* operator->() {
        return m_ptr;
    }

    T* get() {
        if (m_ptr) {
            return m_ptr;
        }
        return nullptr;
    }


private:
    T* m_ptr;
};

#endif // __SMARTPOINTER__