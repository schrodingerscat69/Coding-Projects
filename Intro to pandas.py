import pandas as pd

# A DataFrame is a table. It contains an array of individual entries. each of which
#  has a specific value. Each entry corresponds to a record (row) and a column.
# DataFrame entries are not limited to integer inputs.

# Example:
print(pd.DataFrame({'Yes': [50, 21], 'No': [131, 2]}))

# To declare new DataFrame:
## Keys are column names (must be unique)
## Values are the entries for each key
## To assign column names, use index["r1", ... , "rn"]

#Example:
print(pd.DataFrame({'Hello': ['good','bad'],
              'Hi': ['not','want']},
              index=['PA','PB']))

# Series is a list of data values. Creates one column of a DataFrame
# You can assign row labels using index parameter, add name using
#  name=''

print(pd.Series([30,40,50],
                index = ['s1', 's2','s3'],
                name = 'PA'))

# To read files:
# If file has an index column you want to avoid, use index_col = 0 arg
movie_reviews = pd.read_csv("enter file path", index_col= 0)

# To check how large the DataFrame is:
movie_reviews.shape

# To check contents of first 5 rows of DataFrame:
movie_reviews.head()

# To access a single column from the DataFramce, use:
movie_reviews."Column name"
movie_reviews['Column name']

# To print out a specfic value at index i:
movie_reviews['Column name'][i]

# To select the first row of the DataFrame, you can use:
movie_reviews.iloc[0]
#



