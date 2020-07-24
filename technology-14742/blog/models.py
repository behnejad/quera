from django.db import models
from datetime import datetime


class Author(models.Model):
    name = models.CharField(max_length=50)


class BlogPost(models.Model):
    title = models.CharField(max_length=250)
    body = models.TextField()
    author = models.ForeignKey(Author, on_delete=models.CASCADE, )
    date_created = models.DateTimeField(auto_now_add=datetime.now)

    def copy(self):
        a = BlogPost(title=self.title, body=self.body, author=self.author)
        a.save()
        for b in Comment.objects.filter(blog_post=self):
            b.pk = None
            b.blog_post = a
            b.save()
        return a.pk

class Comment(models.Model):
    blog_post = models.ForeignKey(BlogPost, on_delete=models.CASCADE)
    text = models.CharField(max_length=500)

