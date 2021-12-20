
   
#include <iostream>

struct Data
{
	unsigned int	value;
};

uintptr_t	serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data		*data = new Data;
	
	uintptr_t	serialized;
	Data		*deserialized = NULL;

	data->value = 42;
	
	serialized = serialize(data);
	deserialized = deserialize(serialized);
	
	std::cout << "data address: " << data << std::endl;
	std::cout << "data value: " << data->value << std::endl;
	std::cout << "serialized: " << serialized << std::endl;
	std::cout << "deserialized address: " << deserialized << std::endl;
	std::cout << "deserialized value: " << deserialized->value << std::endl;
	
	delete data;
	
	return 0;
}