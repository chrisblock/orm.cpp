#pragma once

#include <cstdint>

class TestExpressionEntity
{
public:
	TestExpressionEntity();
	TestExpressionEntity(const TestExpressionEntity &other);
	virtual ~TestExpressionEntity();

	TestExpressionEntity &operator =(const TestExpressionEntity &other);

	int32_t _field;

	void SetterGetterSetter(int32_t field);
	int32_t SetterGetterGetter();

	void SetterConstGetterSetter(int32_t field);
	int32_t SetterConstGetterGetter() const;

	void SetterReferenceGetterSetter(int32_t field);
	int32_t &SetterReferenceGetterGetter();

	void SetterConstReferenceGetterSetter(int32_t field);
	const int32_t &SetterConstReferenceGetterGetter() const;

	void ConstSetterGetterSetter(const int32_t field);
	int32_t ConstSetterGetterGetter();

	void ConstSetterConstGetterSetter(const int32_t field);
	int32_t ConstSetterConstGetterGetter() const;

	void ConstSetterReferenceGetterSetter(const int32_t field);
	int32_t &ConstSetterReferenceGetterGetter();

	void ConstSetterConstReferenceGetterSetter(const int32_t field);
	const int32_t &ConstSetterConstReferenceGetterGetter() const;

	void ReferenceSetterGetterSetter(int32_t &field);
	int32_t ReferenceSetterGetterGetter();

	void ReferenceSetterConstGetterSetter(int32_t &field);
	int32_t ReferenceSetterConstGetterGetter() const;

	void ReferenceSetterReferenceGetterSetter(int32_t &field);
	int32_t &ReferenceSetterReferenceGetterGetter();

	void ReferenceSetterConstReferenceGetterSetter(int32_t &field);
	const int32_t &ReferenceSetterConstReferenceGetterGetter() const;

	void ConstReferenceSetterGetterSetter(const int32_t &field);
	int32_t ConstReferenceSetterGetterGetter();

	void ConstReferenceSetterConstGetterSetter(const int32_t &field);
	int32_t ConstReferenceSetterConstGetterGetter() const;

	void ConstReferenceSetterReferenceGetterSetter(const int32_t &field);
	int32_t &ConstReferenceSetterReferenceGetterGetter();

	void ConstReferenceSetterConstReferenceGetterSetter(const int32_t &field);
	const int32_t &ConstReferenceSetterConstReferenceGetterGetter() const;

private:
	int32_t _setterGetter;
	int32_t _setterConstGetter;
	int32_t _setterReferenceGetter;
	int32_t _setterConstReferenceGetter;

	int32_t _constSetterGetter;
	int32_t _constSetterConstGetter;
	int32_t _constSetterReferenceGetter;
	int32_t _constSetterConstReferenceGetter;

	int32_t _referenceSetterGetter;
	int32_t _referenceSetterConstGetter;
	int32_t _referenceSetterReferenceGetter;
	int32_t _referenceSetterConstReferenceGetter;

	int32_t _constReferenceSetterGetter;
	int32_t _constReferenceSetterConstGetter;
	int32_t _constReferenceSetterReferenceGetter;
	int32_t _constReferenceSetterConstReferenceGetter;
};
