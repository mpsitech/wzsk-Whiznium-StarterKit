<template>
	<v-container v-if="initdone">
		<PnlWzskUsrList
			v-on:request="handleRequest"
			ref="PnlWzskUsrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskUsrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskUsrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskUsrList from './PnlWzskUsrList';
	import PnlWzskUsrRec from './PnlWzskUsrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskUsr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskUsrList,
			PnlWzskUsrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskUsr.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzskUsr) this.continf = dpcheng.ContInfWzskUsr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskUsr) this.statapp = dpcheng.StatAppWzskUsr;
				if (dpcheng.StatShrWzskUsr) this.statshr = dpcheng.StatShrWzskUsr;
				if (dpcheng.TagWzskUsr) {
					Wzsk.unescapeBlock(dpcheng.TagWzskUsr);
					this.tag = dpcheng.TagWzskUsr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskUsrList.handleReply(obj);
					else this.$refs.PnlWzskUsrRec.handleReply(obj);
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskUsrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskUsrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskUsrRec.handleUpdate(obj);
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
