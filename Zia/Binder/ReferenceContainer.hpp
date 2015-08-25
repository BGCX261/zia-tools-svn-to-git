#ifndef REFERENCE_CONTAINER_H
#define REFERENCE_CONTAINER_H

namespace binder
{
	template<typename Type>
	class ReferenceContainer
	{
	public:
		ReferenceContainer(Type& ref)
			: _ref(ref)
		{	}

		
		ReferenceContainer&	operator=(const ReferenceContainer& ref)
		{
			this->_ref = ref._ref;
			return *this;
		}

		Type&	getReference() const
		{
			return this->_ref;
		}

		operator Type&()
		{
			return this->_ref;
		}
	
	private:
		Type&	_ref;
	};

	template <typename Type>
    ReferenceContainer<Type>   ref(Type& ref)
    {
		return ReferenceContainer<Type>(ref);
    }
}
#endif