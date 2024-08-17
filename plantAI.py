from dotenv import load_dotenv
import os
import openai

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
        temperature=0.7,  # Controls the randomness of the output
        n=1,              # Number of responses to generate
        stop=None,         # Stop sequence, if any
        stream=False
    )
    return response.choices[0].message.content


