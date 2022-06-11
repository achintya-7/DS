## Movie Recommender powered by Jina AI

# Introduction
Have you ever felt confused and wondered what new movie to watch, or watch a movie of a particular genre or maybe even a new movie that is similar to your favourite movie.

Well, why not make our own Movie Recommender that takes a text query as an input and gives you a list of movies according to the query.

This use case can be thought of as a text search problem where the search system takes input as a text query and searches for movies similar to the query within the database.

# How does it Work?
This recommender uses textual data to find the most relevant movies according to the text provided. We provide the name, description, and genre of the movies to the model from our database.

> Technical Stack → [Jina AI](https://github.com/jina-ai/jina), Rest API, Dart

> Database Used → [IMDB Movies Dataset](https://www.kaggle.com/datasets/harshitshankhdhar/imdb-dataset-of-top-1000-movies-and-tv-shows)

# Architecture Diagram

![image.png](https://cdn.hashnode.com/res/hashnode/image/upload/v1654798428438/aBWSIGF5P.png align="left")

Following is the step-by-step walkthrough of the application logic:

- Fetch the Movies Dataset from Kaggle.
- Add the data to Jina’s DocumentArray for further pre-processing and indexing.
- Pass the DocumentArray to Jina’s Flow for indexing of data using Jina Hub Executors.
- The search flow will encode the input query and search through the indexed data for 
   the nearest match.
- After finding the best possible match, the output data is sent as a Rest API which can be used for various frontend frameworks.

# Code Walkthrough
The key components of this application are building a Flow, indexing, and search functionality. Let’s look at each of them one by one:

**Create a Flow** → The Flow consists of two Executors: `SimpleIndexer` and `TransformerTorchEncoder`

```
from jina import Flow 

flow = (
 Flow(port_expose='12345', protocol='http').add(
  uses="jinahub://TransformerTorchEncoder",
  uses_with={
   "pretrained_model_name_or_path": 
   "sentence-transformers/paraphrase-distilroberta-base-v1"
   },
  name="encoder",
  install_requirements=True
 )
 .add(
  uses="jinahub://SimpleIndexer/latest", 
  uses_metas={"workspace": "workspace"},
  volumes="./workspace:/workspace/workspace",
  name="indexer"
 )
)
``` 


**Create an Index function** → The index function will take the dataset of images in text format converts them into Jina’s native DocumentArray and passes it to the Flow for indexing and searching.

```
with flow as f:    
 f.post(on="/index", inputs=movies, show_progress=True)     
 f.post(on="/", show_progress=True)
 f.cors = True
```

**Create a search function** → The search function takes the text input and makes an HTTP post request to fetch similar movie titles from the Jina backend. The following code is written in Dart for an enhanced user experience.

```
import 'dart:convert';
import 'package:http/http.dart';
 
makePostRequest() async {  
 final uri = Uri.parse('http://192.168.1.9:12345/search');
 final headers = {'Content-Type': 'application/json'};
 var  final_data = [];
 Map<String, dynamic> body = {
    "data": [      
        {"text": "comedy"}
    ],
    "parameters": {"limit": 10}
 };
 String jsonBody = json.encode(body);
 final encoding = Encoding.getByName('utf-8'); 
 Response response = await post(
    uri,
    headers: headers,
    body: jsonBody,
    encoding: encoding,
 );
 int statusCode = response.statusCode;
 String responseBody = response.body;
 print(statusCode);
 var convertedData = jsonDecode(responseBody);
 final_data = convertedData['data'][0]['matches'];
 for (var item in final_data) {
    print(item['tags']['Title']);
  }
} 
void main(List<String> arguments) {
  print("Starting"); 
  makePostRequest();
}
```

And that’s it. It’s this easy to make a neural search engine using Jina AI.

# Movie Recommender in Action

![JinaAi_Flutter.gif](https://cdn.hashnode.com/res/hashnode/image/upload/v1654798346170/T5iCegWq_.gif align="left")

# Learning Resources
- [Jina’s Learning Bootcamp](https://learn.jina.ai/)
- [DocArray Documentation](https://docarray.jina.ai/)
- [Jina Documentation](https://docs.jina.ai/)

# GitHub Repository
For full application source code with Flutter Implementation, check out this [GitHub Repository](https://github.com/achintya-7/Movie_Recommender_Flutter).
