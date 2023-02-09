<template>
    <div class="accounts">
        <Navbar />
        <div v-if="user" class="info my-5">
            <div class="people">
                <div class="child">
                    <img src="../../../front/images/profile.webp" width="120" alt="Profile">
                </div>
                <div class="child">
                    <h1>{{ user.first_name }} {{ user.last_name }}</h1>
                </div>
                <div class="child_left">
                    <p>{{ comments.length }} Comments</p>
                    <p>{{ user.following_nb }} Following</p>
                    <p>{{ user.followers_nb }} Followers</p>
                </div>
            </div>
        </div>
        <div class="comments p-3 mb-5" v-if="comments.length > 0">
            <div class="card my-3 text-start" v-for="comment in comments" :key="comment.id">
              <div class="card-body">
                <h5 style="cursor: pointer;" class="card-title text-right" @click="goToNote(comment.url)">
                  <img id="favicon" :src="getIcon(decodeURIComponent(comment.url))" alt="Favicon" width="40"/>
                  {{ decodeURIComponent(comment.url) }}
                </h5>
                <p class="card-text">{{ comment.content }}</p>
                <button type="button" class="btn btn-danger me-3" style="float: left;" @click="doLike(comment.id)"><i class="fa-sharp fa-solid fa-arrow-down"></i></button>
                <p class="pt-2">{{ comment.value }} <i class="fa-regular fa-thumbs-down"></i></p>
              </div>
            </div>
        </div>
    </div>
</template>

<script>
import Navbar from '../components/Menu.vue'
import Cookies from 'js-cookie'

export default {
  name: 'AccountView',
  data () {
    return {
      user: {},
      comments: []
    }
  },
  components: {
    Navbar
  },
  created () {
    this.getUser()
    this.getComments()
  },
  methods: {
    async getUser () {
      const response = await fetch('/api/user/' + this.$route.params.id)
      const data = await response.json()
      this.user = data
    },
    async getComments () {
      const response = await fetch('/api/comments/' + this.$route.params.id)
      const data = await response.json()
      console.log(data)
      this.comments = data
    },
    getIcon (url) {
      const array = url.split('/')
      if (url.includes('https://')) {
        return 'https://' + array[2] + '/favicon.ico'
      } else if (url.includes('http://')) {
        return 'http://' + array[2] + '/favicon.ico'
      } else {
        return 'https://' + array[0] + '/favicon.ico'
      }
    },
    goToTopic (url) {
      this.$router.push({ name: 'notes', params: { url: decodeURIComponent(url) } })
    },
    async doLike (id) {
      if (Cookies.get('token') === undefined) {
        this.$router.push({ name: 'login' })
      } else {
        const response = await fetch('/api/like', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
            Authorization: 'Bearer ' + Cookies.get('token')
          },
          body: JSON.stringify({
            comment_id: id
          })
        })
        const data = await response.json()
        console.log(data)
        location.reload()
      }
    },
    goToNote (url) {
      this.$router.push({ name: 'notes', params: { url: decodeURIComponent(url) } })
    }
  }
}
</script>

<style>

.header {
    padding-top: 1%;
    padding-bottom: 5%;
}

#menu {
    float: left;
    margin-left: 1%;
}

#icon {
    float: right;
    margin-right: 1%;
}

.people {
    padding: 2rem 2rem;
    margin: 1rem;
    text-align: center;
}

.child {
    display: inline-block;
    padding: 1rem 1rem;
    vertical-align: middle;
}

.child_left {
    display: inline-block;
    text-align: right;
    padding: 1rem 1rem;
    vertical-align: middle;
    margin-left: 30%;
    border-radius: 15%;
    box-shadow: 0px 30px 60px rgba(2, 49, 76, 0.15);
}

.comments {
    background: #FFFFFF;
    box-shadow: 0px 30px 60px rgba(2, 49, 76, 0.15);
    margin-left: 30%;
    margin-right: 30%;
}

.comment {
    padding: 5% 10% 5% 10%;
    text-align: left;
}

p {
    font: "Product Sans" bold;
    color: rgba(1, 30, 47, 0.505);
}

h2 {
    font: "Product Sans" bold;
    font-size: 20px;
    color: rgba(0, 0, 0, 0.97);
}

.likes {
    margin-right: 70%;
}

img.likes {
    float: left;
}

p#dislike {
    font: 11px "Product Sans";
    color: rgba(110, 110, 110, 0.97);
    float: right;
}
</style>
