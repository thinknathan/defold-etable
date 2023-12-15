# defold-etable

A native extension for Defold with functions to manipulate tables in Lua scripts.

Warning: in Lua, table values are not guaranteed to have a stable order.

## Functions

- `etable.empty(table)`
- Clears all values from the given table.

- `etable.remove(table, key)`
- Removes a value with a specific key from a table.

- `etable.index_of(table, value)`
- Finds the index/key of the first occurrence of a value in the given table.

- `etable.slice(table, start_index, end_index)`
- Creates a new table containing a subset of the elements from an existing table.

## Installation

1. Edit game.project
2. Add dependency `https://github.com/thinknathan/defold-etable/archive/main.zip` for the current version
   - Or add a specific [release](https://github.com/thinknathan/defold-etable/releases)

### TypeScript Definitions

This extension includes types for use with [TypeScript + Defold](https://ts-defold.dev/).

1. Install these types

```bash
yarn add git+https://git@github.com/thinknathan/defold-etable.git#^1.0.0 -D
# or
npm install git+https://git@github.com/thinknathan/defold-etable.git#^1.0.0 --save-dev
```

2. Add `defold-etable` to `types` in `tsconfig.json`

```diff
{
	"compilerOptions": {
		"types": [
+			"defold-etable",
		],
	}
}
```

3. Add `node_modules/@types` to `typeRoots` in `tsconfig.json` if it's not already there

```diff
{
	"compilerOptions": {
		"typeRoots": [
+			"node_modules/@types",
		],
	}
}
```

## Usage

```lua
-- Sample table
local myTable = { "apple", "banana", "cherry", "date", "fig" }

-- index_of
-- Finds the index/key of the first occurrence of a value in the given table.
-- If the table is structured like an array, the numerical index is returned.
-- If the table is structured in key/value pairs, the key is returned.
local index = etable.index_of(myTable, "banana")  -- Result: Index of 'banana': 2

-- remove
-- Removes a value with a specific key from a table.
etable.remove(myTable, 4)  -- Result: After remove: apple, banana, cherry, fig

-- slice
-- Creates a new table containing a subset of the elements from an existing table.
-- Start: The starting index
-- End: The ending index (exclusive)
local slicedTable = etable.slice(myTable, 2, 4)  -- Result: Sliced table: banana, cherry, date

-- empty
-- Clears all values from the given table.
etable.empty(myTable)  -- Result: After empty: { }
```

## Background

This extension was created with assistance from Chat-GPT 3.5 and 4.
