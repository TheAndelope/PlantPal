from dotenv import load_dotenv
import os
import openai
import pyttsx3

engine = pyttsx3.init()
load_dotenv()

api_key = os.getenv('OPENAI_API_KEY')

openai.api_key = api_key


def generate_text(model="gpt-4o-mini", max_tokens=40):
    messages = [{"role": "system", "content": "You are a Plant"}]
    messages.append({"role": "user", "content": "I just watered you, tell me a joke"})

    response = openai.chat.completions.create(
        model=model,
        messages=messages,
        max_tokens=max_tokens,
        temperature=1.3,  # Controls the randomness of the output
        n=1,              # Number of responses to generate
        stop=None,         # Stop sequence, if any
        stream=False,
        frequency_penalty = 2.0
    )
    return response.choices[0].message.content

def insult(model="gpt-4o-mini", max_tokens=80):
    messages = [{"role": "system", "content": "You are a Plant"}]
    messages.append({"role": "user", "content": "I've neglected watering you; be SUPER passive aggressive and ask for water"})

    response = openai.chat.completions.create(
        model=model,
        messages=messages,
        max_tokens=max_tokens,
        temperature=1.3,  # Controls the randomness of the output
        n=1,              # Number of responses to generate
        stop=None,         # Stop sequence, if any
        stream=False,
        frequency_penalty = 2.0
    )
    return response.choices[0].message.content

print(insult())