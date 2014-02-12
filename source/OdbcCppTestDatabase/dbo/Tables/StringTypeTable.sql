CREATE TABLE [dbo].[StringTypeTable]
(
	[Id] INT NOT NULL IDENTITY(1, 1),
	[Character] CHAR,
	[WideCharacter] NCHAR,
	[String] VARCHAR(20),
	[WideString] NVARCHAR(20),
	CONSTRAINT [PK__StringTypeTable] PRIMARY KEY ([Id] ASC)
)
