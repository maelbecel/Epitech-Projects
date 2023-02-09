<template>
    <div class="notes">
        <Navbar />
        <div class="logo my-1">
            <img id="poodle" src="../../../front/images/poodle.png" alt="poodle logo" >
        </div>
        <div class="search_bar">
            <form method="get" :action="'/notes/' + encodeURIComponent(search)">
              <input id="search" type="text" placeholder="Search" v-model="search">
            </form>
        </div>
        <div class="info mt-3">
            <div class="child">
                <img id="favicon" :src=" getIcon($route.params.url)" alt="Favicon" width="80">
            </div>
            <div class="child">
                <h1>> {{ $route.params.url }}</h1>
            </div>
        </div>
        <div class="comments p-3" v-if="comments.length > 0">
          <div class="card mb-3 text-start" v-for="comment in comments" :key="comment.id">
              <div class="card-body">
                <h5 style="cursor: pointer;" class="card-title text-right" @click="goToAccount(comment.user_id)">{{ comment.first_name }} {{ comment.last_name }}</h5>
                <p class="card-text">{{ comment.content }}</p>
                <button type="button" class="btn btn-danger me-3" style="float: left;" @click="doLike(comment.id)"><i class="fa-sharp fa-solid fa-arrow-down"></i></button>
                <p class="pt-2">{{ comment.value }} <i class="fa-regular fa-thumbs-down"></i></p>
              </div>
            </div>
        </div>
        <div class="add_comment" v-if="isLoggedIn()">
            <textarea class="form-control" placeholder="Comment" v-model="commentContent"></textarea>
            <button class="btn btn-primary col-12 me-2 mt-2" type="submit" @click="createComment">Send</button>
        </div>
    </div>
</template>

<script>
import Navbar from '../components/Menu.vue'
import Cookies from 'js-cookie'

export default {
  name: 'NotesView',
  data () {
    return {
      search: '',
      commentId: '',
      commentContent: '',
      user: {},
      comments: []
    }
  },
  components: {
    Navbar
  },
  created () {
    this.newTopic()
    this.getTopic()
  },
  methods: {
    async getTopic () {
      console.log('Enter in getTopic')
      const url = encodeURIComponent(this.$route.params.url)
      console.log('SELECT * FROM topics INNER JOIN comments ON topics.id = comments.topic_id INNER JOIN users ON users.id = comments.user_id WHERE comments.url = "' + url + '"')
      const response = await fetch('/api/topic/' + url)
      const data = await response.json()
      console.log(data)
      this.comments = data

      const getid = await fetch('/api/topicid/' + url)
      const dataid = await getid.json()
      this.topicId = dataid[0].id
      console.log('Now on topic ' + this.topicId)
    },
    async createComment () {
      if (this.topicId === undefined) {
        console.log('Undefined topic id')
        console.log(this.comments)
      }
      const response = await fetch('/api/comment', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          user_id: Cookies.get('id'),
          topic_id: this.topicId,
          content: this.commentContent,
          url: decodeURIComponent(this.$route.params.url)
        })
      })
      this.getTopic()
      this.commentContent = ''
      console.log('New comment:')
      console.log(response)
      if (!response.ok) {
        console.log('response is' + response.status)
      }
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
    async newTopic () {
      const response = await fetch('/api/istopic', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          url: decodeURIComponent(this.$route.params.url)
        })
      })
      if (!response.ok) {
        console.log('response Topic exist' + response.status)
      } else {
        await fetch('/api/topic', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json'
          },
          body: JSON.stringify({
            url: decodeURIComponent(this.$route.params.url)
          })
        })
      }
    },
    isLoggedIn () {
      if (Cookies.get('id') === undefined || (Cookies.get('token') === undefined)) {
        console.log('User is not logged in')
        return false
      } else {
        console.log('User is logged in as id:' + Cookies.get('id'))
        return true
      }
    },
    goToAccount (id) {
      this.$router.push({ name: 'account', params: { id: id } })
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

.logo {
    margin-top: -200px;
}

.info {
    margin-top: -50px;
    margin-bottom: -50px;
}

.child {
    display: inline-block;
    padding: 1rem 1rem;
}

#search {
    box-sizing: border-box;
    position: absolute;
    width: 35%;
    height: 5%;
    left: 32.5%;
    border: 1px solid #4E5154;
    border-radius: 8px;
    margin-top: -150px;
}

.comments {
    background: #FFFFFF;
    box-shadow: 0px 30px 60px rgba(2, 49, 76, 0.15);
    margin-left: 30%;
    margin-right: 30%;
    margin-top: 5%;
}

#id {
    position: relative;
    display: block;
    border-radius: 7px;
    width: 30px;
}

#content {
    border-radius: 7px;
    position: absolute;
    display: block;
    height: 70px;
    width: 40%;
}

#next {
    position: relative;
    background: #FFFFFF;
    border-radius: 8px;
    box-shadow: 0px 30px 60px rgba(2, 49, 76, 0.15);
    background-color: #4285F4;
    border-radius: 4px;
    border-width: 0px;
    color: white;
    width: 65px;
    margin-top: 70px;
    float: right;
}

.add_comment {
    text-align: left;
    height: 100px;
    margin-left: 30%;
    margin-right: 30%;
    margin-top: 5%;
    margin-bottom: 10%;
}

</style>
