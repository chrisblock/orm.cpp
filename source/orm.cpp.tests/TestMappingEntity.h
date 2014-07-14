#pragma once

#include <cstdint>

class TestMappingEntity
{
public:
	TestMappingEntity();
	TestMappingEntity(const TestMappingEntity &other);
	virtual ~TestMappingEntity();

	TestMappingEntity &operator =(const TestMappingEntity &other);

	std::int32_t _field;

	void SetterGetterSetter(std::int32_t field);
	std::int32_t SetterGetterGetter();

	void SetterConstGetterSetter(std::int32_t field);
	std::int32_t SetterConstGetterGetter() const;

	void SetterReferenceGetterSetter(std::int32_t field);
	std::int32_t &SetterReferenceGetterGetter();

	void SetterConstReferenceGetterSetter(std::int32_t field);
	const std::int32_t &SetterConstReferenceGetterGetter() const;

	void ConstSetterGetterSetter(const std::int32_t field);
	std::int32_t ConstSetterGetterGetter();

	void ConstSetterConstGetterSetter(const std::int32_t field);
	std::int32_t ConstSetterConstGetterGetter() const;

	void ConstSetterReferenceGetterSetter(const std::int32_t field);
	std::int32_t &ConstSetterReferenceGetterGetter();

	void ConstSetterConstReferenceGetterSetter(const std::int32_t field);
	const std::int32_t &ConstSetterConstReferenceGetterGetter() const;

	void ReferenceSetterGetterSetter(std::int32_t &field);
	std::int32_t ReferenceSetterGetterGetter();

	void ReferenceSetterConstGetterSetter(std::int32_t &field);
	std::int32_t ReferenceSetterConstGetterGetter() const;

	void ReferenceSetterReferenceGetterSetter(std::int32_t &field);
	std::int32_t &ReferenceSetterReferenceGetterGetter();

	void ReferenceSetterConstReferenceGetterSetter(std::int32_t &field);
	const std::int32_t &ReferenceSetterConstReferenceGetterGetter() const;

	void ConstReferenceSetterGetterSetter(const std::int32_t &field);
	std::int32_t ConstReferenceSetterGetterGetter();

	void ConstReferenceSetterConstGetterSetter(const std::int32_t &field);
	std::int32_t ConstReferenceSetterConstGetterGetter() const;

	void ConstReferenceSetterReferenceGetterSetter(const std::int32_t &field);
	std::int32_t &ConstReferenceSetterReferenceGetterGetter();

	void ConstReferenceSetterConstReferenceGetterSetter(const std::int32_t &field);
	const std::int32_t &ConstReferenceSetterConstReferenceGetterGetter() const;

private:
	std::int32_t _setterGetter;
	std::int32_t _setterConstGetter;
	std::int32_t _setterReferenceGetter;
	std::int32_t _setterConstReferenceGetter;

	std::int32_t _constSetterGetter;
	std::int32_t _constSetterConstGetter;
	std::int32_t _constSetterReferenceGetter;
	std::int32_t _constSetterConstReferenceGetter;

	std::int32_t _referenceSetterGetter;
	std::int32_t _referenceSetterConstGetter;
	std::int32_t _referenceSetterReferenceGetter;
	std::int32_t _referenceSetterConstReferenceGetter;

	std::int32_t _constReferenceSetterGetter;
	std::int32_t _constReferenceSetterConstGetter;
	std::int32_t _constReferenceSetterReferenceGetter;
	std::int32_t _constReferenceSetterConstReferenceGetter;
};
