# defold-etable

A native extension for Defold with functions to manipulate tables.

Warning: in Lua, table values are not guaranteed to have a stable order.

## Installation

1. Edit game.project
2. Add dependency `https://github.com/thinknathan/defold-etable/archive/main.zip` for the current version
	- Or add a specific [release](https://github.com/thinknathan/defold-etable/releases)

### TypeScript Definitions

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
-- Find the index/key of a specific value in a Lua table.
-- If the table is structured like an array, the numerical index is returned.
-- If the table is structured in key/value pairs, the key is returned.
local index = etable.index_of(myTable, "banana")  -- Result: Index of 'banana': 2

-- remove
-- Remove a value from a Lua table based on a key.
etable.remove(myTable, 4)  -- Result: After remove: apple, banana, cherry, fig

-- slice
-- Create a new Lua table containing a portion of the elements from the original table.
local slicedTable = etable.slice(myTable, 2, 4)  -- Result: Sliced table: banana, cherry, date

-- empty
-- Remove all entries from the table without allocating a new table.
etable.empty(myTable)  -- Result: After empty: { }
```
