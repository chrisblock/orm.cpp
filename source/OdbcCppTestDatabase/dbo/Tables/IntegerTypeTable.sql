CREATE TABLE [dbo].[IntegerTypeTable]
(
	[Id] INT NOT NULL IDENTITY(1, 1),
	[BitColumn] BIT,
	[TinyIntColumn] TINYINT,
	[SmallIntColumn] SMALLINT,
	[IntColumn] INT,
	[BigIntColumn] BIGINT,
	CONSTRAINT [PK__IntegerTypeTable] PRIMARY KEY ([Id] ASC)
)
