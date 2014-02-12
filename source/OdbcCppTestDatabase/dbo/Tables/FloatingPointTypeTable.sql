CREATE TABLE [dbo].[FloatingPointTypeTable]
(
	[Id] INT NOT NULL IDENTITY(1, 1),
	[Float] FLOAT,
	[Double] REAL,
	[Decimal] DECIMAL,
	[SmallMoney] SMALLMONEY,
	[Money] MONEY,
	CONSTRAINT [PK__FloatingPointTypeTable] PRIMARY KEY ([Id] ASC)
)
