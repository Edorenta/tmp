#!/usr/bin/env python

from flask import Flask, request, render_template

app = Flask(__name__,  template_folder="views")

@app.route("/")
def index():
	return (render_template("index.html"))
if (__name__) == "__main__":
	app.run(debug=True)#debug makes the server auto refresh