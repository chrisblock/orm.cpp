#pragma once

class TestMemberTypesEntity
{
public:
	TestMemberTypesEntity();
	TestMemberTypesEntity(const TestMemberTypesEntity &other);
	virtual ~TestMemberTypesEntity();

	TestMemberTypesEntity &operator =(const TestMemberTypesEntity &other);

	int _integer;

	int Accessor();
	int ConstAccessor() const;
	int &ReferenceAccessor();
	const int &ConstReferenceAccessor() const;

	void Setter(int integer);
	void ConstSetter(const int integer);
	void ReferenceSetter(int &integer);
	void ConstReferenceSetter(const int &integer);
};
