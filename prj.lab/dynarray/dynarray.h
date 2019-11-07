#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

class dynArray {
		ptrdiff_t capacity_{ 0 };
		ptrdiff_t size_{ 0 };
		float* data_{ nullptr };

		dynArray();
public: dynArray(const ptrdiff_t size);
		~dynArray();
		dynArray operator=(const dynArray rhs);
		ptrdiff_t size()const;
		float& operator[](const ptrdiff_t i);
		void resize(const ptrdiff_t size);
};
