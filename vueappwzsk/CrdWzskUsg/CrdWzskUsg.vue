<template>
	<v-container v-if="initdone">
		<PnlWzskUsgList
			v-on:request="handleRequest"
			ref="PnlWzskUsgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskUsgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskUsgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskUsgList from './PnlWzskUsgList';
	import PnlWzskUsgRec from './PnlWzskUsgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskUsg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskUsgList,
			PnlWzskUsgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskUsg.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzskUsg) this.continf = dpcheng.ContInfWzskUsg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskUsg) this.statapp = dpcheng.StatAppWzskUsg;
				if (dpcheng.StatShrWzskUsg) this.statshr = dpcheng.StatShrWzskUsg;
				if (dpcheng.TagWzskUsg) {
					Wzsk.unescapeBlock(dpcheng.TagWzskUsg);
					this.tag = dpcheng.TagWzskUsg;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskUsgList.handleReply(obj);
					else this.$refs.PnlWzskUsgRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskUsgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskUsgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskUsgRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
